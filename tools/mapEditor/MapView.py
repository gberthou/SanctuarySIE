from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

MV_WIDTH = 256
MV_HEIGHT = 256
CELL_SIZE = 32

class LevelCell(QTableWidgetItem):
    def __init__(self, level):
        QTableWidgetItem.__init__(self, str(level.id))
        self.level = level

class MapView(QWidget):
    def __init__(self, amap, parent = None):
        QWidget.__init__(self, parent)

        self.map = amap
        self.selectedLevel = None

        self.lblSelected = QLabel();

        self.table = QTableWidget(MV_WIDTH, MV_HEIGHT, parent)

        self.table.setHorizontalHeaderLabels([str(i) for i in range(MV_WIDTH)])
        self.table.setVerticalHeaderLabels([str(i) for i in range(MV_HEIGHT)])

        self.table.horizontalHeader().setDefaultSectionSize(CELL_SIZE)
        self.table.verticalHeader().setDefaultSectionSize(CELL_SIZE)

        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)

        layout = QVBoxLayout()
        layout.addWidget(self.lblSelected)
        layout.addWidget(self.table)

        self.setLayout(layout)

        self.table.cellClicked.connect(self.onCellClicked)

        self.Update()

    def SetSelectedLevel(self, level):
        self.selectedLevel = level

    def Update(self):
        # Update label
        if self.selectedLevel == None:
            self.lblSelected.setText("No level selected")
        else:
            self.lblSelected.setText("Selected level: %d - %s"%(self.selectedLevel.id, self.selectedLevel.name))

        # Update table
        self.table.clearContents()
        for level in self.map.levels:
            for x in range(level.size[0]):
                for y in range(level.size[1]):
                    px = level.pos[0] + x
                    py = level.pos[1] + y
                    existingItem = self.table.item(py, px)
                    if existingItem == None: # Ok
                        item = LevelCell(level)
                        self.table.setItem(py, px, item)
                    else: # Conflict!
                        text = "%s/%d"%(existingItem.text(), level.id)
                        existingItem.setText(text)
                        existingItem.setBackground(QBrush(QColor(0xFF, 0x00, 0x00)))

    def onCellClicked(self, row, column):
        # If a level is selected, move it
        if self.selectedLevel != None:
            self.selectedLevel.SetPos((column, row))
            self.selectedLevel = None
            self.Update()
        # Else, select the level in the cell
        else:
            item = self.table.item(row, column)
            if item != None:
                self.selectedLevel = item.level
                self.Update()

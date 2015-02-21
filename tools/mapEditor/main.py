from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

import sys

import Map
import Level
import MapController

class MapEditor(QWidget):
    def __init__(self, parent = None):
        QWidget.__init__(self, parent)

        toolbar = QToolBar()
        self.actionNewMap = toolbar.addAction("New Map")
        self.actionOpenMap = toolbar.addAction("Open Map")
        self.actionNewLevel = toolbar.addAction("New Level")
        self.actionAddMob = toolbar.addAction("Add Mob")
        self.actionAddItem = toolbar.addAction("Add Item")
        self.actionAddDoor = toolbar.addAction("Add Door")

        self.projectTree = QTreeWidget()
        self.projectTree.setColumnCount(1)
        self.projectTree.setHeaderLabels(["Project view"])

        self.rootItem = QTreeWidgetItem(self.projectTree, ["Map"])
        self.projectTree.addTopLevelItem(self.rootItem)

        self.displayArea = QWidget()
        
        toolbarLayout = QHBoxLayout()
        toolbarLayout.addWidget(toolbar)

        layout = QHBoxLayout()
        layout.addWidget(self.projectTree)
        layout.addWidget(self.displayArea)

        mainLayout = QVBoxLayout()
        mainLayout.addLayout(toolbarLayout)
        mainLayout.addLayout(layout)

        self.setLayout(mainLayout)
        self.setWindowTitle("SancturarySIE Map Editor")
        self.resize(800, 600)

        self.displayArea.resize(600, 400)

        self.actionNewLevel.triggered.connect(self.newLevel)

        self.map = Map.Map()
        self.controller = MapController.MapController(self.map, self.rootItem)

    def newLevel(self):
        level = Level.Level("Sample", (0, 0), (1, 1))
        self.controller.AddLevel(level)
        self.rootItem.setExpanded(True)

if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = MapEditor()
    window.show()

    sys.exit(app.exec_())


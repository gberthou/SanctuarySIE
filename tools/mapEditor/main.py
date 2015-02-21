from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

import sys

class MapEditor(QWidget):
    def __init__(self, parent = None):
        QWidget.__init__(self, parent)

        toolbar = QToolBar()
        self.actionNewMap = toolbar.addAction("New Map")
        self.actionOpenMap = toolbar.addAction("Open Map")
        self.actionNewLevel = toolbar.addAction("New Level")
        self.actionAddMob = toolbar.addAction("Add Mob")
        self.actionAddItem = toolbar.addAction("Add Item")

        self.projectTree = QTreeView()

        self.displayArea = QWidget()
        
        toolbarLayout = QHBoxLayout()
        toolbarLayout.addWidget(toolbar)

        layout = QHBoxLayout()
        layout.addWidget(self.projectTree)
        layout.addWidget(self.displayArea)

        #self.submitButton.clicked.connect(self.submitContact)

        mainLayout = QVBoxLayout()
        mainLayout.addLayout(toolbarLayout)
        mainLayout.addLayout(layout)

        self.setLayout(mainLayout)
        self.setWindowTitle("SancturarySIE Map Editor")
        self.resize(800, 600)

        self.displayArea.resize(600, 400)

if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = MapEditor()
    window.show()

    sys.exit(app.exec_())


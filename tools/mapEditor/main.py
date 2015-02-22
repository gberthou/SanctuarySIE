from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

import sys

import Map
import Level
import MapController

import DlgNewLevel

class MapEditor(QWidget):
    def __init__(self, parent = None):
        QWidget.__init__(self, parent)

        toolbar = QToolBar()
        self.actionNewMap = toolbar.addAction("New Map")
        self.actionOpenMap = toolbar.addAction("Open Map")
        self.actionSaveMap = toolbar.addAction("Save Map")
        self.actionNewLevel = toolbar.addAction("New Level")
        self.actionAddMob = toolbar.addAction("Add Mob")
        self.actionAddItem = toolbar.addAction("Add Item")
        self.actionAddDoor = toolbar.addAction("Add Door")

        self.projectTree = QTreeWidget()
        self.projectTree.setColumnCount(1)
        self.projectTree.setContextMenuPolicy(Qt.CustomContextMenu)
        self.projectTree.setHeaderLabels(["Project view"])

        self.rootItem = QTreeWidgetItem(self.projectTree, ["Map"])
        self.projectTree.addTopLevelItem(self.rootItem)

        self.projectTree.addAction(QAction("Sample", self.projectTree))
        self.projectTree.customContextMenuRequested.connect(self.onProjectCMenu)
        self.projectTree.currentItemChanged.connect(self.onProjetCurrentItemChanged)

        self.displayMapArea = QWidget()
        self.displayLevelArea = QWidget()

        self.tabView = QTabWidget()
        self.tabView.addTab(self.displayMapArea, "Map view")
        self.tabView.addTab(self.displayLevelArea, "Level view")
        self.tabView.setTabEnabled(1, False) # At the beginning, there is no level
        
        toolbarLayout = QHBoxLayout()
        toolbarLayout.addWidget(toolbar)

        layout = QHBoxLayout()
        layout.addWidget(self.projectTree)
        layout.addWidget(self.tabView)

        mainLayout = QVBoxLayout()
        mainLayout.addLayout(toolbarLayout)
        mainLayout.addLayout(layout)

        self.setLayout(mainLayout)
        self.setWindowTitle("SancturarySIE Map Editor")
        self.resize(800, 600)

        self.actionNewLevel.triggered.connect(self.newLevel)

        self.map = Map.Map()
        self.controller = MapController.MapController(self.map, self.rootItem)

    def onProjectCMenu(self):
        item = self.projectTree.currentItem()

    def onProjetCurrentItemChanged(self, current, previous):
        self.tabView.setTabEnabled(1, current != self.rootItem)

    def newLevel(self):
        dlg = DlgNewLevel.DlgNewLevel(self)
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            level = Level.Level(dlg.GetName(), (0, 0), (dlg.GetValueWidth(), dlg.GetValueHeight()))
            self.controller.AddLevel(level)
            self.rootItem.setExpanded(True)

if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = MapEditor()
    window.show()

    sys.exit(app.exec_())


from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class TreeItemContextual(QTreeWidgetItem):
    def __init__(self, parent, strings):
        QTreeWidgetItem.__init__(self, parent, strings)
        self.menu = None

    def SetMenu(self, menu):
        self.menu = menu

class LevelItem(TreeItemContextual):
    def __init__(self, parent, strings, level):
        TreeItemContextual.__init__(self, parent, strings)
        self.level = level

    def SetLevel(self, menu):
        self.level = level

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from DlgSetBg import *
from DlgSetColMap import *

class TreeItemContextual(QTreeWidgetItem):
    def __init__(self, parent, strings):
        QTreeWidgetItem.__init__(self, parent, strings)
        self.menu = None

    def SetMenu(self, menu):
        self.menu = menu

class LevelItem(TreeItemContextual):
    def __init__(self, parent, level, options):
        TreeItemContextual.__init__(self, parent, ["%d - %s"%(level.id, level.name)])
        self.level = level
        self.options = options
        self.itemPos = TreeItemContextual(self, [level.GetPosText()])
        self.itemSize = TreeItemContextual(self, [level.GetSizeText()])
        self.itemBgs = BackgroundsItem(self, ["Backgrounds"], level)
        self.itemCollision = TreeItemContextual(self, [level.GetCollisionMapText()])
        self.itemMobs = TreeItemContextual(self, ["Mobs"])
        self.itemItems = TreeItemContextual(self, ["Items"])
        self.itemDoors = TreeItemContextual(self, ["Doors"])

        itemMenu = QMenu()
        actionSetBg = itemMenu.addAction("Set backgrounds")
        actionSetColMap = itemMenu.addAction("Set collision map")

        self.SetMenu(itemMenu)

        actionSetBg.triggered.connect(self.setBgs)
        actionSetColMap.triggered.connect(self.setColMap)

    def SetLevel(self, menu):
        self.level = level

    def SetPos(self, pos):
        self.level.SetPos(pos)
        self.itemPos.setText(0, self.level.GetPosText())

    def setBgs(self):
        dlg = DlgSetBg(None, self.level.backgrounds, self.options.resourceRoot)  
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            self.level.SetBgs(dlg.GetBgs())
            self.itemBgs.updateItems()

    def setColMap(self):
        dlg = DlgSetColMap(None, self.level.collisionMap, self.options.resourceRoot)  
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            self.level.SetCollisionMap(dlg.GetColmap())
            self.itemCollision.setText(0, self.level.GetCollisionMapText())

class BackgroundsItem(TreeItemContextual):
    def __init__(self, parent, strings, level):
        TreeItemContextual.__init__(self, parent, strings)
        self.level = level
        self.items = [None] * 4

        self.updateItems()

    def updateItems(self):
        for i, item in enumerate(self.items):
            text = "[%d] %s"%(i, self.level.backgrounds[i] if self.level.backgrounds[i] != None else "Null")
            if item == None:
                self.items[i] = TreeItemContextual(self, [text])
            else:
                self.items[i].setText(0, text)


from PyQt5.QtWidgets import *

from DlgSetBg import *

from TreeItemContextual import *

class MapController:
    def __init__(self, uiParent, amap, rootItem):
        self.uiParent = uiParent
        self.map = amap
        self.rootItem = rootItem

    def AddLevel(self, level):
        # Update model
        self.map.AddLevel(level)

        # Update view
        item = LevelItem(self.rootItem, [level.name], level)
        itemPos = TreeItemContextual(item, [level.GetPosText()])
        itemSize = TreeItemContextual(item, [level.GetSizeText()])
        itemBgs = TreeItemContextual(item, ["Backgrounds"])
        itemCollision = TreeItemContextual(item, [level.GetCollisionMapText()])
        itemMobs = TreeItemContextual(item, ["Mobs"])
        itemItems = TreeItemContextual(item, ["Items"])
        itemDoors = TreeItemContextual(item, ["Doors"])

        for i,bg in enumerate(level.backgrounds):
            it = TreeItemContextual(itemBgs, ["[%d] %s"%(i, bg if bg != None else "Null")])

        itemMenu = QMenu(self.uiParent)
        actionSetBg = itemMenu.addAction("Set backgrounds")

        item.SetMenu(itemMenu)

        actionSetBg.triggered.connect(lambda: self.SetBgs(level))

    def SetBgs(self, level):
        dlg = DlgSetBg(self.uiParent)  
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            pass


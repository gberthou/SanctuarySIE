from PyQt5.QtWidgets import *

class MapController:
    def __init__(self, amap, rootItem):
        self.map = amap
        self.rootItem = rootItem

    def AddLevel(self, level):
        # Update model
        self.map.AddLevel(level)

        # Update view
        item = QTreeWidgetItem([level.name])
        itemPos = QTreeWidgetItem([level.GetPosText()])
        itemSize = QTreeWidgetItem([level.GetSizeText()])
        itemBgs = QTreeWidgetItem(["Backgrounds"])
        itemCollision = QTreeWidgetItem([level.GetCollisionMapText()])
        itemMobs = QTreeWidgetItem(["Mobs"])
        itemItems = QTreeWidgetItem(["Items"])
        itemDoors = QTreeWidgetItem(["Doors"])

        for i,bg in enumerate(level.backgrounds):
            it = QTreeWidgetItem(["[%d] %s"%(i, bg if bg != None else "Null")])
            itemBgs.addChild(it)

        item.addChild(itemPos)
        item.addChild(itemSize)
        item.addChild(itemBgs)
        item.addChild(itemCollision)
        item.addChild(itemMobs)
        item.addChild(itemItems)
        item.addChild(itemDoors)

        self.rootItem.addChild(item)


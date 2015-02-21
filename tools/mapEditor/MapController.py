from PyQt5.QtWidgets import *

class MapController:
    def __init__(self, amap, rootItem):
        self.map = amap
        self.rootItem = rootItem

    def AddLevel(self, level):
        # Update model
        self.map.AddLevel(level)

        # Update view
        self.rootItem.addChild(QTreeWidgetItem([level.name]))


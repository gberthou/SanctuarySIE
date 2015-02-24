from PyQt5.QtWidgets import *

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

        
            


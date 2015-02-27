from PyQt5.QtWidgets import *

from TreeItemContextual import *

class MapController:
    def __init__(self, uiParent, options, amap, rootItem):
        self.uiParent = uiParent
        self.options = options
        self.map = amap
        self.rootItem = rootItem
        self.items = {}

    def AddLevel(self, level):
        # Update model
        self.map.AddLevel(level)

        # Update view
        self.items[level.id] = LevelItem(self.rootItem, level, self.options)

    def SetPos(self, levelId, pos):
        try:
            self.items[levelId].SetPos(pos)
        except KeyError:
            pass


class Map:
    def __init__(self):
        # Editor attributes
        self.lastLevelId = 0

        # Core attributes
        self.levels = []
        self.doors = []
        

    def AddLevel(self, level):
        level.SetId(self.lastLevelId)        
        self.levels.append(level)
        self.lastLevelId += 1


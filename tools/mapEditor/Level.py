class Level:
    def __init__(self, name, pos, size):
        self.name = name
        self.pos = pos
        self.size = size
        self.backgrounds = [None] * 4
        self.collisionMap = None
        self.mobs = []
        self.items = []
        self.doors = []

    def GetPosText(self):
        return "Pos: (%d, %d)" % self.pos
    def GetSizeText(self):
        return "Size: (%d, %d)" % self.size
    def GetCollisionMapText(self):
        prefix = "CollisionMap:"        
        if self.collisionMap == None:
            return "%s Null" % prefix
        else:
            return "%s %s" % (prefix, self.collisionMap)


class Level:
    def __init__(self, name, pos, size):
        # Editor attributes        
        self.name = name
        self.id = 0

        # Core attributes
        self.pos = pos
        self.size = size
        self.backgrounds = [None] * 4
        self.collisionMap = None
        self.mobs = []
        self.items = []
        self.doors = []

    def SetId(self, id):
        self.id = id

    def SetBgs(self, bgs):
        self.backgrounds = bgs

    def SetPos(self, pos):
        self.pos = pos

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


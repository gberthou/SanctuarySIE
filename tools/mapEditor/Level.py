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


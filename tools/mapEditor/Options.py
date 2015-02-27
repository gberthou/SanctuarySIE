import configparser

OPT_GLOBAL = "GLOBAL"
OPT_RESOURCEROOT = "resourceRoot"

class Options:
    def __init__(self):
        self.resourceRoot = None

    def Save(self, path):
        conf = configparser.ConfigParser()
        conf[OPT_GLOBAL] = {OPT_RESOURCEROOT : "" if self.resourceRoot == None else self.resourceRoot}
        with open(path, "w") as file:
            conf.write(file)

    def Load(self, path):
        conf = configparser.ConfigParser()
        if len(conf.read(path)) > 0:
            if OPT_GLOBAL in conf:
                if OPT_RESOURCEROOT in conf[OPT_GLOBAL]:
                    self.resourceRoot = conf[OPT_GLOBAL][OPT_RESOURCEROOT]
                else:
                    self.resourceRoot = None
            else:
                self.resourceRoot = None

    def SetResourceRoot(self, path):
        self.resourceRoot = path


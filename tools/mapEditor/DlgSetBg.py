import pathlib

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgSetBg import *

"""
def getRelativePath(a, b):
    parentsA = a.parents
    parentsB = b.parents

    for i in range(min(len(parentsA), len(parentsB))):
        if parentsA[i] == parentsB[i]:
            ret = pathlib.PurePath("./") if i == 0 else pathlib.PurePath(("../")*i)
            j = len(b.parts) - 1 - i
            print(j)
            print(len(b.parts))
            while j < len(b.parts):
                ret = ret.joinpath(b.parts[j])
                j += 1
            return ret
"""

class DlgSetBg(QDialog):
    def __init__(self, parent, bgs, resourcePath):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgSetBg()
        self.ui.setupUi(self)
        self.bindEvents()
        self.fields = [self.ui.leBg0, self.ui.leBg1, self.ui.leBg2, self.ui.leBg3]
       
        self.bgs=bgs
        for i in range(4):
            self.fields[i].setText("" if bgs[i] == None else bgs[i])

        self.resourcePath = resourcePath

    def bindEvents(self):
        self.ui.btnBrowse0.clicked.connect(lambda: self.browseBg(0))
        self.ui.btnBrowse1.clicked.connect(lambda: self.browseBg(1))
        self.ui.btnBrowse2.clicked.connect(lambda: self.browseBg(2))
        self.ui.btnBrowse3.clicked.connect(lambda: self.browseBg(3))

    def browseBg(self, i):
        dlg = QFileDialog(self)
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            absPath = pathlib.PurePath(dlg.selectedFiles()[0])
            """absResourcePath = pathlib.PurePath(self.resourcePath)
            print(getRelativePath(absPath, absResourcePath))"""
            try:
                path = absPath.relative_to(self.resourcePath)
                self.bgs[i] = str(path)
                self.fields[i].setText(self.bgs[i])
            except ValueError:
                print("The resource must be child of the given resource root path.\nCheck your options.")

    def GetBgs(self):
        return self.bgs

    


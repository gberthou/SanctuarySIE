from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgSetBg import *

class DlgSetBg(QDialog):
    def __init__(self, parent = None):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgSetBg()
        self.ui.setupUi(self)
        self.bindEvents()

        self.bgs=[None]*4

    def bindEvents(self):
        self.ui.btnBrowse0.clicked.connect(lambda: self.browseBg(0))
        self.ui.btnBrowse1.clicked.connect(lambda: self.browseBg(1))
        self.ui.btnBrowse2.clicked.connect(lambda: self.browseBg(2))
        self.ui.btnBrowse3.clicked.connect(lambda: self.browseBg(3))

    def browseBg(self, i):
        dlg = QFileDialog(self)
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            fields = [self.ui.leBg0, self.ui.leBg1, self.ui.leBg2, self.ui.leBg3]
            self.bgs[i] = dlg.selectedFiles()[0]
            fields[i].setText(self.bgs[i])

    def GetBgs(self):
        return self.bgs

    


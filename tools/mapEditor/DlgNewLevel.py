from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgNewLevel import *

class DlgNewLevel(QDialog):
    def __init__(self, parent = None):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgNewLevel()
        self.ui.setupUi(self)

    def GetValueWidth(self):
        return self.ui.sboxWidth.value()

    def GetValueHeight(self):
        return self.ui.sboxHeight.value()


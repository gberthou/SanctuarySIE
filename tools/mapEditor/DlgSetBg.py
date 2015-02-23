from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgSetBg import *

class DlgSetBg(QDialog):
    def __init__(self, parent = None):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgSetBg()
        self.ui.setupUi(self)

    


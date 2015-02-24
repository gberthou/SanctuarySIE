from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

MV_WIDTH = 256
MV_HEIGHT = 256
CELL_SIZE = 32

class MapView(QTableWidget):
    def __init__(self, parent = None):
        QTableWidget.__init__(self, MV_WIDTH, MV_HEIGHT, parent)

        self.setHorizontalHeaderLabels([str(i) for i in range(MV_WIDTH)])
        self.setVerticalHeaderLabels([str(i) for i in range(MV_HEIGHT)])

        self.horizontalHeader().setDefaultSectionSize(CELL_SIZE)
        self.verticalHeader().setDefaultSectionSize(CELL_SIZE)

        self.setEditTriggers(QAbstractItemView.NoEditTriggers)

        

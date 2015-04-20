import pathlib

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgSetColMap import *

class DlgSetColMap(QDialog):
    def __init__(self, parent, colmap, resourcePath):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgSetColMap()
        self.ui.setupUi(self)
        self.bindEvents()
        self.colmap = None

        self.ui.leColmap.setText("" if colmap == None else colmap)

        self.resourcePath = resourcePath

    def bindEvents(self):
        self.ui.btnBrowse.clicked.connect(self.browse)

    def browse(self):
        dlg = QFileDialog(self)
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            absPath = pathlib.PurePath(dlg.selectedFiles()[0])
            try:
                path = absPath.relative_to(self.resourcePath)
                self.colmap = str(path)
                self.ui.leColmap.setText(self.colmap)
            except ValueError:
                print("The resource must be child of the given resource root path.\nCheck your options.")

    def GetColmap(self):
        return self.colmap

    


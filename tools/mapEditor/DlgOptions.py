from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

from Ui_DlgOptions import *

class DlgOptions(QDialog):
    def __init__(self, parent, options):
        QDialog.__init__(self, parent)
        self.ui = Ui_DlgOptions()
        self.ui.setupUi(self)
        self.bindEvents()
       
        self.options=options
        if self.options.resourceRoot != None:
            self.ui.leResourceRoot.setText(self.options.resourceRoot)

    def bindEvents(self):
        self.ui.btnResourceBrowse.clicked.connect(self.browseResourceRoot)

    def browseResourceRoot(self):
        dlg = QFileDialog(self)
        dlg.setFileMode(QFileDialog.Directory);
        code = dlg.exec()

        if code == 1: # "Ok" has been pressed
            path = dlg.selectedFiles()[0]
            self.options.SetResourceRoot(path)
            self.ui.leResourceRoot.setText(path)


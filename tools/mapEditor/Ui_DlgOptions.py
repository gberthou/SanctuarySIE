# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './ui/options.ui'
#
# Created: Fri Feb 27 09:52:08 2015
#      by: PyQt5 UI code generator 5.4
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DlgOptions(object):
    def setupUi(self, DlgOptions):
        DlgOptions.setObjectName("DlgOptions")
        DlgOptions.resize(400, 83)
        self.buttonBox = QtWidgets.QDialogButtonBox(DlgOptions)
        self.buttonBox.setGeometry(QtCore.QRect(10, 50, 381, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.horizontalLayoutWidget = QtWidgets.QWidget(DlgOptions)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(10, 10, 381, 31))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.leResourceRoot = QtWidgets.QLineEdit(self.horizontalLayoutWidget)
        self.leResourceRoot.setReadOnly(True)
        self.leResourceRoot.setObjectName("leResourceRoot")
        self.horizontalLayout.addWidget(self.leResourceRoot)
        self.btnResourceBrowse = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.btnResourceBrowse.setObjectName("btnResourceBrowse")
        self.horizontalLayout.addWidget(self.btnResourceBrowse)

        self.retranslateUi(DlgOptions)
        self.buttonBox.accepted.connect(DlgOptions.accept)
        self.buttonBox.rejected.connect(DlgOptions.reject)
        QtCore.QMetaObject.connectSlotsByName(DlgOptions)

    def retranslateUi(self, DlgOptions):
        _translate = QtCore.QCoreApplication.translate
        DlgOptions.setWindowTitle(_translate("DlgOptions", "Dialog"))
        self.label.setText(_translate("DlgOptions", "Resources root path"))
        self.btnResourceBrowse.setText(_translate("DlgOptions", "Browse..."))


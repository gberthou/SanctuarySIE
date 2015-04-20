# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './ui/setcolmap.ui'
#
# Created by: PyQt5 UI code generator 5.4.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DlgSetColMap(object):
    def setupUi(self, DlgSetColMap):
        DlgSetColMap.setObjectName("DlgSetColMap")
        DlgSetColMap.resize(410, 94)
        self.buttonBox = QtWidgets.QDialogButtonBox(DlgSetColMap)
        self.buttonBox.setGeometry(QtCore.QRect(10, 60, 381, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.layoutWidget = QtWidgets.QWidget(DlgSetColMap)
        self.layoutWidget.setGeometry(QtCore.QRect(10, 20, 381, 31))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.layoutWidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.leColmap = QtWidgets.QLineEdit(self.layoutWidget)
        self.leColmap.setReadOnly(True)
        self.leColmap.setObjectName("leColmap")
        self.horizontalLayout.addWidget(self.leColmap)
        self.btnBrowse = QtWidgets.QPushButton(self.layoutWidget)
        self.btnBrowse.setObjectName("btnBrowse")
        self.horizontalLayout.addWidget(self.btnBrowse)

        self.retranslateUi(DlgSetColMap)
        self.buttonBox.accepted.connect(DlgSetColMap.accept)
        self.buttonBox.rejected.connect(DlgSetColMap.reject)
        QtCore.QMetaObject.connectSlotsByName(DlgSetColMap)

    def retranslateUi(self, DlgSetColMap):
        _translate = QtCore.QCoreApplication.translate
        DlgSetColMap.setWindowTitle(_translate("DlgSetColMap", "Set collision map"))
        self.label.setText(_translate("DlgSetColMap", "Collision map path: "))
        self.btnBrowse.setText(_translate("DlgSetColMap", "Browse..."))


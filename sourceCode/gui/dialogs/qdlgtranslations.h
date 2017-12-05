
#ifndef QDLGTRANSLATIONS_H
#define QDLGTRANSLATIONS_H

#include "dlgEx.h"
#include "7Vector.h"

namespace Ui {
    class CQDlgTranslations;
}

class QComboBox;

class CQDlgTranslations : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgTranslations(QWidget *parent = 0);
    ~CQDlgTranslations();

    void refresh();

    void cancelEvent();

protected:
    void _enableCoordinatePart(bool enableState,bool anglePart,bool enableButtons,bool alsoRadioButtons);
    void _enableTransformationPart(bool enableState,int partIndex,bool enableButtons,bool alsoRadioButtons);
    void _setDefaultValuesCoordinatePart(bool anglePart,bool alsoRadioButtons);
    void _setDefaultValuesTransformationPart(int partIndex,bool alsoRadioButtons);
    void _setValuesTransformationPart(int partIndex,bool alsoRadioButtons);

    // Coord part
    bool _setCoord_userUnit(float newValueInUserUnit,int index);
    C7Vector _getNewTransf(const C7Vector& transf,float newValueInUserUnit,int index);
    bool _applyCoord(int mask);
    void _copyTransf(const C7Vector& tr,C7Vector& trIt,int mask);

    // Transf part
    bool _applyTransformation(int t);
    void _transform(C7Vector& tr,int t,bool self);

    static int coordMode; //0=abs,1=rel to parent
    static float rotAngles[3];
    static float translationValues[3];
    static float scalingValues[3];
    static int transfMode; //0=abs,1=rel to parent,2=rel to self

    int lastLastSelectionID;

private slots:
    void on_qqCoordWorld_clicked();

    void on_qqCoordParent_clicked();

    void on_qqCoordX_editingFinished();

    void on_qqCoordY_editingFinished();

    void on_qqCoordZ_editingFinished();

    void on_qqCoordApplyPos_clicked();

    void on_qqCoordApplyX_clicked();

    void on_qqCoordApplyY_clicked();

    void on_qqCoordApplyZ_clicked();

    void on_qqTransfWorld_clicked();

    void on_qqTransfParent_clicked();

    void on_qqTransfOwn_clicked();

    void on_qqTransfX_editingFinished();

    void on_qqTransfY_editingFinished();

    void on_qqTransfZ_editingFinished();

    void on_qqTransfApplyPos_clicked();

    void on_qqTransfSX_editingFinished();

    void on_qqTransfSY_editingFinished();

    void on_qqTransfSZ_editingFinished();

    void on_qqTransfApplyScale_clicked();

private:
    Ui::CQDlgTranslations *ui;
};

#endif // QDLGTRANSLATIONS_H
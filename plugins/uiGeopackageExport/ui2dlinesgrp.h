 
#ifndef ui2dlinesgrp_h
#define ui2dlinesgrp_h

#include "uidlggroup.h"

class uiCheckBox;
class uiSeis2DLineSelGrp;

class ui2DLinesGrp : public uiDlgGroup
{ mODTextTranslationClass(ui2DLinesGrp);
public:
    ui2DLinesGrp(uiParent*);
    
    void getGeoMids( TypeSet<Pos::GeomID>& geomids );
    bool doLineExport();
    bool doStationExport();
    void reset();
    
protected:
    uiCheckBox* exp2DStationsfld_;
    uiSeis2DLineSelGrp* lineselfld_;
};

#endif
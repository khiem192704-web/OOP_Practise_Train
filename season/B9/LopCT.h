#include"LopTT.h"
class LopCT : public LopTT{
    public:
        LopCT();
        ~LopCT();
        //A(), B() = 0
        void B() override;
};

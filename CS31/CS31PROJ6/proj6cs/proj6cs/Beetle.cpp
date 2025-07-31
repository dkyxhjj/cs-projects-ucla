//
//  Beetle.cpp
//
//

#include "Beetle.h"

namespace cs31
{

Beetle::Beetle()
{
    mBody = false;
    mTail = false;
    mLeg1 = false;
    mLeg2 = false;
    mLeg3 = false;
    mLeg4 = false;
    mHead = false;
    mEye1 = false;
    mEye2 = false;
    mAntenna1 = false;
    mAntenna2 = false;
}

// convert a tossed die value into a BodyPart
Beetle::BodyPart Beetle::convertRollToBodyPart( int die ) const
{
    // if not matching, then return NOTVALID
    BodyPart part = BodyPart::NOTVALID;
    if (die == 6)
        part = BodyPart::BODY;
    if (die == 5)
        part = BodyPart::HEAD;
    if (die == 4)
        part = BodyPart::TAIL;
    if (die == 3)
        part = BodyPart::LEG;
    if (die == 2)
        part = BodyPart::ANTENNA;
    if (die == 1)
        part = BodyPart::EYE;
    return( part );
}

// build the Beetle's body
void Beetle::buildBody()
{
    mBody = true;
    
}

// has the Beetle's body been built?
bool Beetle::hasBody() const
{
    return (mBody);
}

// build the Beetle's tail but only if the body has already been built
void Beetle::buildTail(){
    mTail = true;
}


// has the Beetle's tail been built?
bool Beetle::hasTail() const
{
    // for now...
    return (mTail);
}

// build the Beetle's leg but only if the body has already been built
void Beetle::buildLeg()
{
    if (!hasLeg1())
        mLeg1 = true;
    else if (!hasLeg2())
        mLeg2 = true;
    else if (!hasLeg3())
        mLeg3 = true;
    else if (!hasLeg4())
        mLeg4 = true;
    
    
}

// has the Beetle's leg been built?
bool Beetle::hasLeg1() const
{
    return(mLeg1);
}

bool Beetle::hasLeg2() const
{
    return(mLeg2);
}

bool Beetle::hasLeg3() const
{
    return(mLeg3);
}

bool Beetle::hasLeg4() const
{
    return(mLeg4);
}

// build the Beetle's head but only if the body has already been built
void Beetle::buildHead()
{
    mHead = true;
    
    
}

// has the Beetle's head been built?
bool Beetle::hasHead() const
{
    return (mHead);
}

// build the Beetle's eye but only if the head has already been built
void Beetle::buildEye(){
    if (!hasEye1())
        mEye1 = true;
    else if (!hasEye2())
        mEye2 = true;
}

// has the Beetle's eye been built?
bool Beetle::hasEye1() const
{
    return (mEye1);
}

bool Beetle::hasEye2() const
{
    return (mEye2);
}

// build the Beetle's antenna but only if the head has already been built
void Beetle::buildAntenna()
{
    if (!hasAntenna1())
        mAntenna1 = true;
    else if (!hasAntenna2())
        mAntenna2 = true;
    
    
}

// has the Beetle's antenna been built?
bool Beetle::hasAntenna1() const
{
    return(mAntenna1);
}

bool Beetle::hasAntenna2() const
{
    return(mAntenna2);
}


// is this Beetle completely built out?
bool Beetle::isComplete() const
{
    return (
            hasBody() &&
            hasTail() &&
            hasLeg1() && hasLeg2() && hasLeg3() && hasLeg4() &&
            hasHead() &&
            hasEye1() && hasEye2() &&
            hasAntenna1() && hasAntenna2()
        );
}


}



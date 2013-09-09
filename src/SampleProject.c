#include "SampleProject.h"
#include "SampleProjectPrivate.h"

EN_Mode iGetMode( const struct ST_PimplInst_tag *pstData )
{
    /* check parameter */
    if( pstData == NULL ){
        return -1;
    }
    return pstData->eMode;
}

void vSetMode( struct ST_PimplInst_tag *pstData, EN_Mode eMode )
{
    /* check parameter */
    if( pstData == NULL ){
        return;
    }
    if(
        ( eMode < MODE_0 ) ||
        ( MODE_MAX < eMode )
    ){
        return;
    }
    pstData->eMode = eMode;

    return;
}

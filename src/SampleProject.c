#include "SampleProject.h"
#include "SampleProjectPrivate.h"

static EN_Mode iGetMode( struct ST_PimplInst_tag *pstData )
{
    /* check parameter */
    if( pstData == NULL ){
        return -1;
    }
    return pstData->eMode;
}

void vSetMode( const struct ST_PimplInst_tag *pstData, EN_Mode eMode )
{
    /* check parameter */
    if( pstData == NULL ){
        return -1;
    }
    if(
        ( eMode < MODE_0 ) ||
        ( MODE_MAX < eMode )
    ){
        return -1;
    }
    pstData->eMode = eMode;

    return;
}

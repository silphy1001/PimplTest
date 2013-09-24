#include "SampleProject.h"
#include "SampleProjectPrivate.h"
#include <errno.h>

EN_RetCode eInitPimplInstance( ST_PimplInst **pstPimpl )
{
	EN_RetCode eRet = RET_OK;

	if( pstPimpl == NULL ){
		return RET_ERR_PARAM;
	}

	*pstPimpl = ( ST_PimplInst * )malloc( sizeof( ST_PimplInst ) * 1 );
	if( *pstPimpl == NULL ){
		int iErrNo = errno;
		printf( "[%d] - %s\n", iErrNo, strerror( iErrNo ) );
		eRet = RET_ERR_SYSTEM;
	}

	return eRet;
}

EN_RetCode eDeinitPimplInstance( ST_PimplInst **pstPimpl )
{
	EN_RetCode eRet = RET_OK;

	if( pstPimpl == NULL ){
		return RET_ERR_PARAM;
	}

	if( *pstPimpl == NULL ){
		/* Nothing to do */
		return RET_NOTHING_TO_DO;
	}else{
		free( *pstPimpl );
		pstPimpl = NULL;
	}

	return eRet;
}

EN_Mode eGetMode( const struct ST_PimplInst_tag *pstData )
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


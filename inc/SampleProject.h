#ifndef SAMPLE_PROJECT_H__
#define SAMPLE_PROJECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    MODE_0 = 0,
    MODE_1,
    MODE_2,
    MODE_3,
    MODE_MAX
}EN_Mode;

typedef enum{
	RET_ERR_SYSTEM = -3,
	RET_ERR_PARAM,
	RET_ERR_GENERAL,
	RET_OK,
	RET_NOTHING_TO_DO
}EN_RetCode;

struct ST_PimplInst_tag *gpstPmplInst;

typedef EN_RetCode (*pTeConstruct)( struct ST_PimplInst_tag **pstData );
typedef EN_RetCode (*pTeDestruct)( struct ST_PimplInst_tag **pstData );
typedef EN_Mode (*pTeGetMode)( const struct ST_PimplInst_tag *pstData );
typedef void (*pTvSetMode)( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

extern EN_RetCode eInitPimplInstance( struct ST_PimplInst_tag **pstPimpl );
extern EN_RetCode eDeinitPimplInstance( struct ST_PimplInst_tag **pstPimpl );
extern EN_Mode eGetMode( const struct ST_PimplInst_tag *pstData );
extern void vSetMode( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

#endif /* SAMPLE_PROJECT_H__ */

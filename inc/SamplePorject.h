#ifndef SAMPLE_PROJECT_H__
#define SAMPLE_PROJECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef{
    MODE_0 = 0,
    MODE_1,
    MODE_2,
    MODE_3,
    MODE_MAX
}EN_Mode;

struct ST_PimplInst_tag *gpstPmplInst;

typedef EN_Mode (*pTeGetMode)( struct ST_PimplInst_tag *pstData );
typedef void (*pTvSetMode)( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

extern static EN_Mode iGetMode( struct ST_PimplInst_tag *pstData );
extern void vSetMode( const struct ST_PimplInst_tag *pstData, EN_Mode eMode );

typedef ST_SampleStruct{
    struct ST_PimplInst_tag *pstPimplInst;
    pTeGetMode peGetMode;
    pTvSetMode pvSetMode;
}ST_SampleStruct;

#endif /* SAMPLE_PROJECT_H__ */

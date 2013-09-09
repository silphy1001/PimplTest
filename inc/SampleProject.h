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

struct ST_PimplInst_tag *gpstPmplInst;

typedef EN_Mode (*pTeGetMode)( struct ST_PimplInst_tag *pstData );
typedef void (*pTvSetMode)( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

extern EN_Mode iGetMode( const struct ST_PimplInst_tag *pstData );
extern void vSetMode( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

typedef struct ST_SampleStruct_tag{
    struct ST_PimplInst_tag *pstPimplInst;
    pTeGetMode peGetMode;
    pTvSetMode pvSetMode;
}ST_SampleStruct;

#endif /* SAMPLE_PROJECT_H__ */

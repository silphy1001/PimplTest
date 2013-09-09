#ifndef SAMPLE_PROJECT_PRIV_H__
#define SAMPLE_PROJECT_PRIV_H__

#include "SampleProject.h"

typedef struct ST_PimplInst_tag{
    EN_Mode eMode;
}ST_PimplInst;

extern EN_Mode iGetMode( const struct ST_PimplInst_tag *pstData );
extern void vSetMode( struct ST_PimplInst_tag *pstData, EN_Mode eMode );

#endif /* SAMPLE_PROJECT_PRIV_H__ */

#include "SampleProject.h"
#include <stdio.h>

typedef struct ST_SampleStruct_tag{
	struct ST_PimplInst_tag *pstPimplInst;
	pTeConstruct peConstruct;
	pTeGetMode   peGetMode;
	pTvSetMode   pvSetMode;
	pTeDestruct  peDestruct;
}ST_SampleStruct;

void vInitSampleStruct( ST_SampleStruct *pstSampleData );
void vDeinitSampleStruct( ST_SampleStruct *pstSampleData );
void vPrintMember( ST_SampleStruct *pstSampleStruct );

int main( int argc, char *argv[] )
{
	ST_SampleStruct stData = { 0 };

    printf( "Start SampleProject!!\n\n" );

	printf( "Setup SampleStruct --->\n" );
	printf( "BEFORE init\n" );
	vPrintMember( &stData );
	vInitSampleStruct( &stData );
	printf( "AFTER init\n" );
	vPrintMember( &stData );
	printf( "<--- Setup SampleStruct\n\n" );
	
	printf( "CurrentMode=%d\n", stData.peGetMode( stData.pstPimplInst ) );
	printf( "SetMode=%d\n", MODE_3 );
	stData.pvSetMode( stData.pstPimplInst, MODE_3 );
	printf( "CurrentMode=%d\n\n", stData.peGetMode( stData.pstPimplInst ) );

	vDeinitSampleStruct( &stData );
	printf( "AFTER deinit\n\n" );
	vPrintMember( &stData );

    return 0;
}

void vPrintMember( ST_SampleStruct *pstSampleStruct )
{
	if( pstSampleStruct == NULL ){
		printf( "pstSampleStruct point NULL\n" );
		return;
	}
	printf( "    pstPimplinst=%p\n", pstSampleStruct->pstPimplInst );
	printf( "    peConstruct=%p\n", pstSampleStruct->peConstruct );
	printf( "    peDestruct=%p\n", pstSampleStruct->peDestruct );
	printf( "    pvSetMode=%p\n", pstSampleStruct->pvSetMode );
	printf( "    peGetMode=%p\n", pstSampleStruct->peGetMode );
}

void vInitSampleStruct( ST_SampleStruct *pstSampleData )
{
	if( pstSampleData == NULL ){
		printf( "Failed: init target, as target point NULL\n" );
		return;
	}

	pstSampleData->peConstruct = eInitPimplInstance;
	pstSampleData->peDestruct  = eDeinitPimplInstance;
	pstSampleData->pvSetMode   = vSetMode;
	pstSampleData->peGetMode   = eGetMode;
	if( pstSampleData->peConstruct( &( pstSampleData->pstPimplInst ) ) != RET_OK ){
		printf( "Failed: Construction for pstPimplInst\n" );
		memset( pstSampleData, 0x0, sizeof( ST_SampleStruct ) * 1 );
		return;
	}
}

void vDeinitSampleStruct( ST_SampleStruct *pstSampleData )
{
	EN_RetCode eRet = RET_OK;

	if( pstSampleData == NULL ){
		printf( "Failed: deinit target, as target point NULL\n" );
		return;
	}
	
	eRet = pstSampleData->peDestruct( &( pstSampleData->pstPimplInst ) );
	if(
			( eRet != RET_OK ) &&
			( eRet != RET_NOTHING_TO_DO )
	  ){
		printf( "Failed: Destruction for pstPimplInst\n" );
		return;
	}
	memset( pstSampleData, 0x0, sizeof( ST_SampleStruct ) * 1 );
}


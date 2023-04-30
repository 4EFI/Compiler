
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin_trtor.h"

//-----------------------------------------------------------------------------

int BinTrtorCtor( BinTrtor* bin_trtor, const char* bin_code )
{
    size_t size = CheckBinCodeSignature( bin_code );
    if(   !size   ) return 0;

    bin_trtor->bin_code = ( char* )( bin_code + SignatureBlockSize );
    bin_trtor->num_cmds = 0;

    bin_trtor->bin_code_size = size;
    bin_trtor->commands      = ( Command* )calloc( bin_trtor->bin_code_size, sizeof( Command ) ); 
    
    return 1;
}

//-----------------------------------------------------------------------------

int BinTrtorDtor( BinTrtor* bin_trtor )
{
    bin_trtor->bin_code = NULL;

    free( bin_trtor->commands );
    bin_trtor->commands = NULL;

    bin_trtor->num_cmds      = 0;
    bin_trtor->bin_code_size = 0;

    return 1;
}

//-----------------------------------------------------------------------------

int BinTrtorParseBinCode( BinTrtor* bin_trtor )
{
    char* curr_str_ptr = bin_trtor->bin_code;
    
    for( int i = 0; i < bin_trtor->bin_code_size; i++ )
    {
        
        
        bin_trtor->num_cmds++;
    }
    
    return 1;
}

//-----------------------------------------------------------------------------

int CheckBinCodeSignature( const char* bin_code )
{
    int  version      = 0;
    char signature[3] = "";
    int  code_size    = 0;

    sscanf( bin_code, "%s %d %d", signature, &version, &code_size ); 

    // check 
    if( !strcmp( signature, Signature ) && version == Version ) return code_size;

    return 0;
}

//-----------------------------------------------------------------------------
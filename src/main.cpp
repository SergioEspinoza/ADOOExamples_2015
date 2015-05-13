#include "Logger.hpp"
#include "ErrorLogger.hpp"
#include "WarningLogger.hpp"
#include "DebugLogger.hpp"


void main( String[] args )
{

    Logger* logger;
    ErrorLogger* errLoger;
    WarningLogger* warnLogger;
    DebugLogger* debugLogger;

    errLogger = new ErrorLogger( "dumpLog" );
    warnLogger = new WarningLogger( "dumpLog"  );
    debugLogger = new DebuLogger( "dumpLog" );

    // substitute with final method names 

    errLogger.log( "log from error logger 1" );
    warnLogger.log( "log from warning logger 1" );
    debugLogger.log( "log from debugLogger 1"  );

    errLogger.errorLog( "errorLog from error logger 1" );
    warnLogger.warningLog( "warningLog from warning logger 1" );
    debugLogger.debugLog( "debugLog from debugLogger 1"  );

    // cast to base class type

     logger =  static_cast< Logger* >(debugLogger);
    // call should be succesfull
     logger.log( "log from debug logger base class" );


    return 0;
}

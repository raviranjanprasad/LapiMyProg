#define LOGFILE	"error.log"     // all ErrLog(); messages will be appended to this file
extern int ErrLogCreated;      // keeps track whether the log file is created or not
void ErrLog (char *message);    // logs a Error message to LOGFILE


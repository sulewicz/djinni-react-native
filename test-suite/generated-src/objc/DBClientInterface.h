// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from client_interface.djinni

#import "DBClientReturnedRecord.h"
#import <Foundation/Foundation.h>


@protocol DBClientInterface

/** Returns record of given string */
- (nonnull DBClientReturnedRecord *)getRecord:(int64_t)recordId
                                   utf8string:(nonnull NSString *)utf8string
                                         misc:(nullable NSString *)misc;

@end

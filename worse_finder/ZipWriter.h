//
//  ZipWriter.h
//  worse_finder
//
//  Minimal streaming ZIP writer: deflate or store, ZIP64 when needed.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZipWriter : NSObject

+ (nullable instancetype)writerAtPath:(NSString *)path;

/// Writes the archive straight to a (non-seekable) file descriptor — a pipe or
/// socket — using data descriptors instead of seeking back to patch headers.
/// Lets the server stream a ZIP on the fly without staging it on disk.
+ (nullable instancetype)streamingWriterToFileDescriptor:(int)fd;

- (BOOL)addDirectory:(NSString *)entry;
- (BOOL)addFile:(NSString *)source entry:(NSString *)entry;
- (BOOL)close;

@property (nonatomic, readonly) NSString * _Nullable lastError;
@property (nonatomic, readonly) uint64_t entriesWritten;
@property (nonatomic, readonly) uint64_t filesSkipped;
@property (nonatomic, readonly) uint64_t bytesWritten;

@end

NS_ASSUME_NONNULL_END

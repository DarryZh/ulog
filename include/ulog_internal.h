#ifndef __ULOG_INTERNAL_H__
#define __ULOG_INTERNAL_H__

//these functions do not check level versus uLOCAL_LEVEL, this should be done in ulog.h
void ulog_buffer_hex_internal(const char *tag, const void *buffer, uint16_t buff_len, ulog_level_t level);
void ulog_buffer_char_internal(const char *tag, const void *buffer, uint16_t buff_len, ulog_level_t level);
void ulog_buffer_hexdump_internal( const char *tag, const void *buffer, uint16_t buff_len, ulog_level_t log_level);

#endif

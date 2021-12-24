#include <cstdio>
#include <vector>
#include <memory>
#include <stdarg.h>

/**
 * Logger
 */

class Logger {
public:
  Logger() : m_buff(2048) {}

  void log(const char *format, ...);
  void va_log(const char* format, va_list ap);

private:
  std::vector<char> m_buff;
};

void Logger::log(const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  va_log(format, ap);
  va_end(ap);
}

void Logger::va_log(const char* format, va_list ap) {
  m_buff[0] = '\0';

  const int max_bytes = m_buff.size();
  const int bytes_written = vsnprintf(m_buff.data(), max_bytes, format, ap);

  if (bytes_written >= max_bytes)
    m_buff[max_bytes - 1] = '\0';

  printf("%s", m_buff.data());
}

class LogFactory {
public:
  static std::shared_ptr <Logger> getLogger();
};

#define LOG(FORMAT, ...) LogFactory::getLogger()->log(FORMAT, ##__VA_ARGS__)

/**
 * Input
 */

class Input {
public:
  Input() { LOG("%s\n", __FUNCTION__); }
  ~Input() { LOG("%s\n", __FUNCTION__); }

  static Input *instance();

  void keyPressed(long long _keyPressed);
};

void Input::keyPressed(long long _keyPressed) {
  LOG("keyPressed: %lld\n", _keyPressed);
}

/**
 * Input globals
 */

static Input s_instance;

Input* Input::instance() {
  return &s_instance;
}

/**
 * Logger globals
 */

Logger *create_default_logger() {
  return new Logger();
}

std::shared_ptr <Logger> g_logger;

std::shared_ptr <Logger> LogFactory::getLogger() {
  if (!g_logger) {
    g_logger.reset(create_default_logger());
  }

  return g_logger;
}

/**
 * main
 */

int main() {
  Input::instance()->keyPressed(0);

  return 0;
}

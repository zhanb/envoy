#pragma once

#include <string>

#include "envoy/api/api.h"

#include "common/stats/isolated_store_impl.h"

#include "test/test_common/utility.h"

namespace Envoy {

/**
 * Class for Schemas supported by validation tool.
 */
class Schema {
public:
  /**
   * List of supported schemas to validate.
   */
  enum Type { Route };

  /**
   * Get a string representation of the schema type.
   * @param type to convert.
   * @return string representation of type.
   */
  static const std::string& toString(Type type);

private:
  static const std::string ROUTE;
};

/**
 * Parses command line arguments for Schema Validator Tool.
 */
class Options {
public:
  Options(int argc, char** argv);

  /**
   * @return the schema type.
   */
  Schema::Type schemaType() const { return schema_type_; }

  /**
   * @return the path to JSON file.
   */
  const std::string& jsonPath() const { return json_path_; }

private:
  Schema::Type schema_type_;
  std::string json_path_;
};

/**
 * Validates the schema of a JSON.
 */
class Validator {
public:
  Validator() : api_(Api::createApiForTest(stats_)) {}
  /**
   * Validates the JSON at config_path against schema_type.
   * An EnvoyException is thrown in several cases:
   *  - Cannot load the JSON from config_path(invalid path or malformed JSON).
   *  - A schema error from validating the JSON.
   * @param json_path specifies the path to the JSON file.
   * @param schema_type specifies the schema to validate the JSON against.
   */
  void validate(const std::string& json_path, Schema::Type schema_type);

private:
  Stats::IsolatedStoreImpl stats_;
  Api::ApiPtr api_;
};

} // namespace Envoy

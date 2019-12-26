import NativeModulesCoursework from "../lib/binding";

it("understanding module.exports", () => {
  exports.key1 = "value1";
  expect(Object.keys(module.exports)).toEqual(1);
  expect(exports.key1).toEqual("value1");

  const key2 = "key2";
  const value2 = "value2";
  exports[key2] = value2;
  expect(Object.keys(module.exports)).toEqual(2);
  expect(exports.key2).toEqual(value2);

  expect(() => (module.exports = {})).not.toThrow();
  expect(Object.keys(module.exports)).toEqual(0);
  module.exports = {
    key1: "Value1",
    key2: "Value2"
  };
  expect(exports.key1).toEqual("Value1");
  expect(exports.key2).toEqual("Value2");
});

it("creating and returning a native module", () => {
  const { section2 } = new NativeModulesCoursework();
  expect(typeof section2).toEqual("string");
  expect(section2).toEqual("hello world");
});

process.env.NODE_ENV = "testing";

module.exports = {
  roots: ["src/"],
  preset: "ts-jest",
  testEnvironment: "node"
};

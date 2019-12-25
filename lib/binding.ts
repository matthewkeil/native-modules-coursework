const bindings: Bindings = require("../build/Release/native-modules-coursework");

interface Bindings {
  section3: {
    boolean: boolean;
    number: number;
    string: string;
    symbol: Symbol;
    array: number[];
  };
  example3: () => string;
  example4: (arg: string) => string;
  example5: (arg: string, cb: (arg: string) => void) => void;

  // ObjectReference
  // PropertyDescriptor
  // Name
  // Env
  // Value: napi_value
  // CallbackInfo
  // Reference
  // External
}

class NativeModulesCoursework {
  //   public example1 = bindings.example1;
  //   public example2 = bindings.example2;
  //   public example3 = bindings.example3;
  //   public example4 = bindings.example4;
  //   public example5 = bindings.example5;
  //   public example6 = bindings.example6;
  //   public example7 = bindings.example7;
}

export = NativeModulesCoursework;

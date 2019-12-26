const bindings: Bindings = require("../build/Release/native-modules-coursework");

interface Bindings {
  section2: string;
  section3: {
    undefined: undefined;
    null: null;
    symbol: Symbol;
    boolean: boolean;
    string: string;
    number: number;
    array: any[];
    // available in N-API 4
    // bigInt: BigInt;
    // date: Date;
  };
  section4: {
    returnsAValue: () => string;
    takesAParameter: (arg: string) => string;
    takesACallback: (arg: string, cb: (arg: string) => void) => void;
  };

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
  public section2 = bindings.section2;
  public section3 = bindings.section3;
}

export = NativeModulesCoursework;

const addon = require('../build/Release/native-modules-coursework-native');

interface INativeModulesCourseworkNative
{
    greet(strName: string): string;
};

class NativeModulesCoursework {
    constructor(name: string) {
        this._addonInstance = new addon.NativeModulesCoursework(name)
    }

    greet (strName: string) {
        return this._addonInstance.greet(strName);
    }

    // private members
    private _addonInstance: INativeModulesCourseworkNative;
}

export = NativeModulesCoursework;

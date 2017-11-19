/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   Shkoder_1989_Black_otf;
    const int            Shkoder_1989_Black_otfSize = 10796;

    extern const char*   Lombok_otf;
    const int            Lombok_otfSize = 30884;

    extern const char*   SHPinscherRegular_otf;
    const int            SHPinscherRegular_otfSize = 180932;

    extern const char*   Norsk_ttf;
    const int            Norsk_ttfSize = 7956;

    extern const char*   VotuTypeface_ttf;
    const int            VotuTypeface_ttfSize = 203680;

    extern const char*   ZEBRAIRR_TTF;
    const int            ZEBRAIRR_TTFSize = 108244;

    extern const char*   Shkoder_1989_Light_otf;
    const int            Shkoder_1989_Light_otfSize = 11192;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 7;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

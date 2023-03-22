#define EJSON_EXPAND(x) x
#define EJSON_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12,     \
                        _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, \
                        _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, \
                        _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, \
                        _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, \
                        _57, _58, _59, _60, _61, _62, _63, _64, NAME, ...)     \
   NAME
#define EJSON_ARG2_PASTE(...)                                                  \
   EJSON_EXPAND(EJSON_GET_MACRO(                                               \
     __VA_ARGS__, EJSON_PLACEHOLDER, EJSON_ARGS62_PASTE31, EJSON_PLACEHOLDER,  \
     EJSON_ARGS60_PASTE30, EJSON_PLACEHOLDER, EJSON_ARGS58_PASTE29,            \
     EJSON_PLACEHOLDER, EJSON_ARGS56_PASTE28, EJSON_PLACEHOLDER,               \
     EJSON_ARGS54_PASTE27, EJSON_PLACEHOLDER, EJSON_ARGS52_PASTE26,            \
     EJSON_PLACEHOLDER, EJSON_ARGS50_PASTE25, EJSON_PLACEHOLDER,               \
     EJSON_ARGS48_PASTE24, EJSON_PLACEHOLDER, EJSON_ARGS46_PASTE23,            \
     EJSON_PLACEHOLDER, EJSON_ARGS44_PASTE22, EJSON_PLACEHOLDER,               \
     EJSON_ARGS42_PASTE21, EJSON_PLACEHOLDER, EJSON_ARGS40_PASTE20,            \
     EJSON_PLACEHOLDER, EJSON_ARGS38_PASTE19, EJSON_PLACEHOLDER,               \
     EJSON_ARGS36_PASTE18, EJSON_PLACEHOLDER, EJSON_ARGS34_PASTE17,            \
     EJSON_PLACEHOLDER, EJSON_ARGS32_PASTE16, EJSON_PLACEHOLDER,               \
     EJSON_ARGS30_PASTE15, EJSON_PLACEHOLDER, EJSON_ARGS28_PASTE14,            \
     EJSON_PLACEHOLDER, EJSON_ARGS26_PASTE13, EJSON_PLACEHOLDER,               \
     EJSON_ARGS24_PASTE12, EJSON_PLACEHOLDER, EJSON_ARGS22_PASTE11,            \
     EJSON_PLACEHOLDER, EJSON_ARGS20_PASTE10, EJSON_PLACEHOLDER,               \
     EJSON_ARGS18_PASTE9, EJSON_PLACEHOLDER, EJSON_ARGS16_PASTE8,              \
     EJSON_PLACEHOLDER, EJSON_ARGS14_PASTE7, EJSON_PLACEHOLDER,                \
     EJSON_ARGS12_PASTE6, EJSON_PLACEHOLDER, EJSON_ARGS10_PASTE5,              \
     EJSON_PLACEHOLDER, EJSON_ARGS8_PASTE4, EJSON_PLACEHOLDER,                 \
     EJSON_ARGS6_PASTE3, EJSON_PLACEHOLDER, EJSON_ARGS4_PASTE2,                \
     EJSON_PLACEHOLDER, EJSON_ARGS2_PASTE1, EJSON_PLACEHOLDER,                 \
     EJSON_PLACEHOLDER)(__VA_ARGS__))

#define EJSON_ARGS2_PASTE1(func, v1, v2) func(v1, v2)
#define EJSON_ARGS4_PASTE2(func, v1, v2, v3, v4)                               \
   EJSON_ARGS2_PASTE1(func, v1, v2) EJSON_ARGS2_PASTE1(func, v3, v4)
#define EJSON_ARGS6_PASTE3(func, v1, v2, v3, v4, v5, v6)                       \
   EJSON_ARGS4_PASTE2(func, v1, v2, v3, v4) EJSON_ARGS2_PASTE1(func, v5, v6)
#define EJSON_ARGS8_PASTE4(func, v1, v2, v3, v4, v5, v6, v7, v8)               \
   EJSON_ARGS6_PASTE3(func, v1, v2, v3, v4, v5, v6)                            \
   EJSON_ARGS2_PASTE1(func, v7, v8)
#define EJSON_ARGS10_PASTE5(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)     \
   EJSON_ARGS8_PASTE4(func, v1, v2, v3, v4, v5, v6, v7, v8)                    \
   EJSON_ARGS2_PASTE1(func, v9, v10)
#define EJSON_ARGS12_PASTE6(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12)                                          \
   EJSON_ARGS10_PASTE5(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)          \
   func(v11, v12)
#define EJSON_ARGS14_PASTE7(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14)                                \
   EJSON_ARGS12_PASTE6(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12)                                                    \
   func(v13, v14)
#define EJSON_ARGS16_PASTE8(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14, v15, v16)                      \
   EJSON_ARGS14_PASTE7(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14)                                          \
   func(v15, v16)
#define EJSON_ARGS18_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,     \
                            v11, v12, v13, v14, v15, v16, v17, v18)            \
   EJSON_ARGS16_PASTE8(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14, v15, v16)                                \
   func(v17, v18)
#define EJSON_ARGS20_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) \
   EJSON_ARGS18_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,     \
                       v12, v13, v14, v15, v16, v17, v18)                      \
   func(v19, v20)
#define EJSON_ARGS22_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22)                                         \
   EJSON_ARGS20_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20)           \
   func(v21, v22)
#define EJSON_ARGS24_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24)                               \
   EJSON_ARGS22_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22) \
   func(v23, v24)
#define EJSON_ARGS26_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26)                     \
   EJSON_ARGS24_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24)                                              \
   func(v25, v26)
#define EJSON_ARGS28_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28)           \
   EJSON_ARGS26_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26)                                    \
   func(v27, v28)
#define EJSON_ARGS30_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30) \
   EJSON_ARGS28_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28)                          \
   func(v29, v30)
#define EJSON_ARGS32_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32)                                         \
   EJSON_ARGS30_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30)                \
   func(v31, v32)
#define EJSON_ARGS34_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34)                               \
   EJSON_ARGS32_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)      \
   func(v33, v34)
#define EJSON_ARGS36_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36)                     \
   EJSON_ARGS34_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34)                                                   \
   func(v35, v36)
#define EJSON_ARGS38_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38)           \
   EJSON_ARGS36_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36)                                         \
   func(v37, v38)
#define EJSON_ARGS40_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40) \
   EJSON_ARGS38_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38)                               \
   func(v39, v40)
#define EJSON_ARGS42_PASTE21(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)                       \
   EJSON_ARGS40_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40)                     \
   func(v41, v42)
#define EJSON_ARGS44_PASTE22(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)             \
   EJSON_ARGS42_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42)           \
   func(v43, v44)
#define EJSON_ARGS46_PASTE23(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)   \
   EJSON_ARGS44_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44) \
   func(v45, v46)
#define EJSON_ARGS48_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, \
                             v41, v42, v43, v44, v45, v46, v47, v48)           \
   EJSON_ARGS46_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46)                                              \
   func(v47, v48)
#define EJSON_ARGS50_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,    \
                             v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, \
                             v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, \
                             v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, \
                             v41, v42, v43, v44, v45, v46, v47, v48, v49, v50) \
   EJSON_ARGS48_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48)                                    \
   func(v49, v50)
#define EJSON_ARGS52_PASTE26(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52)                                                \
   EJSON_ARGS50_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50)                          \
   func(v51, v52)
#define EJSON_ARGS54_PASTE27(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54)                                      \
   EJSON_ARGS52_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52)                \
   func(v53, v54)
#define EJSON_ARGS56_PASTE28(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)                            \
   EJSON_ARGS54_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)      \
   func(v55, v56)
#define EJSON_ARGS58_PASTE29(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)                  \
   EJSON_ARGS56_PASTE28(                                                       \
     func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15,   \
     v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29,     \
     v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43,     \
     v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)          \
   func(v57, v58)
#define EJSON_ARGS60_PASTE30(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)        \
   EJSON_ARGS58_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                        v56, v57, v58)                                         \
   func(v59, v60)
#define EJSON_ARGS62_PASTE31(                                                  \
  func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
  v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
  v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
  v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
  v62)                                                                         \
   EJSON_ARGS60_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,    \
                        v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, \
                        v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, \
                        v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, \
                        v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                        v56, v57, v58, v59, v60)                               \
   func(v61, v62)

#define EJSON_PASTE_WITH_TYPE(...)                                             \
   EJSON_EXPAND(EJSON_GET_MACRO(                                               \
     __VA_ARGS__, EJSON_TYPE_PASTE62, EJSON_TYPE_PASTE61, EJSON_TYPE_PASTE60,  \
     EJSON_TYPE_PASTE59, EJSON_TYPE_PASTE58, EJSON_TYPE_PASTE57,               \
     EJSON_TYPE_PASTE56, EJSON_TYPE_PASTE55, EJSON_TYPE_PASTE54,               \
     EJSON_TYPE_PASTE53, EJSON_TYPE_PASTE52, EJSON_TYPE_PASTE51,               \
     EJSON_TYPE_PASTE50, EJSON_TYPE_PASTE49, EJSON_TYPE_PASTE48,               \
     EJSON_TYPE_PASTE47, EJSON_TYPE_PASTE46, EJSON_TYPE_PASTE45,               \
     EJSON_TYPE_PASTE44, EJSON_TYPE_PASTE43, EJSON_TYPE_PASTE42,               \
     EJSON_TYPE_PASTE41, EJSON_TYPE_PASTE40, EJSON_TYPE_PASTE39,               \
     EJSON_TYPE_PASTE38, EJSON_TYPE_PASTE37, EJSON_TYPE_PASTE36,               \
     EJSON_TYPE_PASTE35, EJSON_TYPE_PASTE34, EJSON_TYPE_PASTE33,               \
     EJSON_TYPE_PASTE32, EJSON_TYPE_PASTE31, EJSON_TYPE_PASTE30,               \
     EJSON_TYPE_PASTE29, EJSON_TYPE_PASTE28, EJSON_TYPE_PASTE27,               \
     EJSON_TYPE_PASTE26, EJSON_TYPE_PASTE25, EJSON_TYPE_PASTE24,               \
     EJSON_TYPE_PASTE23, EJSON_TYPE_PASTE22, EJSON_TYPE_PASTE21,               \
     EJSON_TYPE_PASTE20, EJSON_TYPE_PASTE19, EJSON_TYPE_PASTE18,               \
     EJSON_TYPE_PASTE17, EJSON_TYPE_PASTE16, EJSON_TYPE_PASTE15,               \
     EJSON_TYPE_PASTE14, EJSON_TYPE_PASTE13, EJSON_TYPE_PASTE12,               \
     EJSON_TYPE_PASTE11, EJSON_TYPE_PASTE10, EJSON_TYPE_PASTE9,                \
     EJSON_TYPE_PASTE8, EJSON_TYPE_PASTE7, EJSON_TYPE_PASTE6,                  \
     EJSON_TYPE_PASTE5, EJSON_TYPE_PASTE4, EJSON_TYPE_PASTE3,                  \
     EJSON_TYPE_PASTE2, EJSON_TYPE_PASTE1, EJSON_PLACEHOLDER,                  \
     EJSON_PLACEHOLDER)(__VA_ARGS__))

#define SETTER_FUNC(name, rename)                                              \
   template <typename T>                                                       \
   void set##rename(const T& v)                                                \
   {                                                                           \
      this->name = v;                                                          \
   }
#define SETTER_FUNC_CHAIN(Type, name, rename)                                  \
   template <typename T>                                                       \
   Type& set##rename(const T& v)                                               \
   {                                                                           \
      this->name = v;                                                          \
      return *this;                                                            \
   }
#define GETTER_FUNC(name, rename)                                              \
   template <typename T>                                                       \
   T get##rename() const                                                       \
   {                                                                           \
      return this->name;                                                       \
   }

#define AUTO_GEN_GETTER_SETTER(...)                                            \
   EJSON_EXPAND(EJSON_ARG2_PASTE(GETTER_FUNC, __VA_ARGS__))                    \
   EJSON_EXPAND(EJSON_ARG2_PASTE(SETTER_FUNC, __VA_ARGS__))

//#define AUTO_GEN_GETTER_SETTER_CHAIN(...)                                      \
//   EJSON_EXPAND(EJSON_ARG2_PASTE(GETTER_FUNC, __VA_ARGS__))                    \
//   EJSON_EXPAND(EJSON_ARG2_PASTE(SETTER_FUNC_CHAIN, __VA_ARGS__))

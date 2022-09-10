
#ifndef __pixy_h__
#define __pixy_h__

#ifdef __cplusplus
extern "C" {
#endif

#define PIXYAPI

/*! @brief One.
 */
#define PIXY_TRUE 1

/*! @brief Zero.
 */
#define PIXY_FALSE 0

/*! @brief Window hints.
 *
 *  Window hints.
 */
enum {
    /*! The OpenGL context major version.
     */
    PIXY_CONTEXT_VERSION_MAJOR,
    /*! The OpenGL context minor version.
     */
    PIXY_CONTEXT_VERSION_MINOR,
    /*! The OpenGL context profile.
     */
    PIXY_OPENGL_PROFILE,
    /*! Forward compatible OpenGL context.
     */
    PIXY_CONTEXT_FORWARD_COMPAT,
    /*! Client API.
     */
    PIXY_CLIENT_API,
};

/*! @brief Window hint values.
 *
 *  Window hint values.
 */
enum {
    /*! PIXY_OPENGL_PROFILE
     */
    /*! OpenGL Core Profile.
     */
    PIXY_OPENGL_CORE_PROFILE,
    /*! OpenGL Compatiblity Profile.
     */
    PIXY_OPENGL_COMPATIBLITY_PROFILE,

    /*! PIXY_CLIENT_API
     */
    /*! No client API.
     */
    PIXY_NO_API,
    /*! OpenGL Client API.
     */
    PIXY_OPENGL_API,
};

/*! @brief Key values.
 *
 *  Key values.
 */
enum {
    PIXY_UNKNOWN_KEY                = -1,

    PIXY_KEY_SPACE                  = ' ',
    PIXY_KEY_APOSTROPHE             = '\'',
    PIXY_KEY_COMMA                  = ',',
    PIXY_KEY_MINUS                  = '-',
    PIXY_KEY_PERIOD                 = '.',
    PIXY_KEY_SLASH                  = '/',

    PIXY_KEY_0                      = '0',
    PIXY_KEY_1,
    PIXY_KEY_2,
    PIXY_KEY_3,
    PIXY_KEY_4,
    PIXY_KEY_5,
    PIXY_KEY_6,
    PIXY_KEY_7,
    PIXY_KEY_8,
    PIXY_KEY_9,

    PIXY_KEY_SEMICOLON              = ';',
    PIXY_KEY_EQUAL                  = '=',

    PIXY_KEY_A                      = 'A',
    PIXY_KEY_B,
    PIXY_KEY_C,
    PIXY_KEY_D,
    PIXY_KEY_E,
    PIXY_KEY_F,
    PIXY_KEY_G,
    PIXY_KEY_H,
    PIXY_KEY_I,
    PIXY_KEY_J,
    PIXY_KEY_K,
    PIXY_KEY_L,
    PIXY_KEY_M,
    PIXY_KEY_N,
    PIXY_KEY_O,
    PIXY_KEY_P,
    PIXY_KEY_Q,
    PIXY_KEY_R,
    PIXY_KEY_S,
    PIXY_KEY_T,
    PIXY_KEY_U,
    PIXY_KEY_V,
    PIXY_KEY_W,
    PIXY_KEY_X,
    PIXY_KEY_Y,
    PIXY_KEY_Z,

    PIXY_KEY_LEFT_BRACKET           = '[',
    PIXY_KEY_BACKSLASH              = '\\',
    PIXY_KEY_RIGHT_BRACKET          = ']',
    PIXY_KEY_GRAVE_ACCENT           = '`',

    PIXY_KEY_WORLD_1                = 161,
    PIXY_KEY_WORLD_2                = 162,

    PIXY_KEY_ESCAPE                 = 256,
    PIXY_KEY_ENTER                  = 257,
    PIXY_KEY_TAB                    = 258,
    PIXY_KEY_BACKSPACE              = 259,
    PIXY_KEY_INSERT                 = 260,
    PIXY_KEY_DELETE                 = 261,
    PIXY_KEY_RIGHT                  = 262,
    PIXY_KEY_LEFT                   = 263,
    PIXY_KEY_DOWN                   = 264,
    PIXY_KEY_UP                     = 265,
    PIXY_KEY_PAGE_UP                = 266,
    PIXY_KEY_PAGE_DOWN              = 267,
    PIXY_KEY_HOME                   = 268,
    PIXY_KEY_END                    = 269,

    PIXY_KEY_CAPS_LOCK              = 280,
    PIXY_KEY_SCROLL_LOCK            = 281,
    PIXY_KEY_NUM_LOCK               = 282,
    PIXY_KEY_PRINT_SCREEN           = 283,
    PIXY_KEY_PAUSE                  = 284,
    PIXY_KEY_F1                     = 290,
    PIXY_KEY_F2                     = 291,
    PIXY_KEY_F3                     = 292,
    PIXY_KEY_F4                     = 293,
    PIXY_KEY_F5                     = 294,
    PIXY_KEY_F6                     = 295,
    PIXY_KEY_F7                     = 296,
    PIXY_KEY_F8                     = 297,
    PIXY_KEY_F9                     = 298,
    PIXY_KEY_F10                    = 299,
    PIXY_KEY_F11                    = 300,
    PIXY_KEY_F12                    = 301,
    PIXY_KEY_F13                    = 302,
    PIXY_KEY_F14                    = 303,
    PIXY_KEY_F15                    = 304,
    PIXY_KEY_F16                    = 305,
    PIXY_KEY_F17                    = 306,
    PIXY_KEY_F18                    = 307,
    PIXY_KEY_F19                    = 308,
    PIXY_KEY_F20                    = 309,
    PIXY_KEY_F21                    = 310,
    PIXY_KEY_F22                    = 311,
    PIXY_KEY_F23                    = 312,
    PIXY_KEY_F24                    = 313,
    PIXY_KEY_F25                    = 314,

    PIXY_KEY_KP_0                   = 320,
    PIXY_KEY_KP_1                   = 321,
    PIXY_KEY_KP_2                   = 322,
    PIXY_KEY_KP_3                   = 323,
    PIXY_KEY_KP_4                   = 324,
    PIXY_KEY_KP_5                   = 325,
    PIXY_KEY_KP_6                   = 326,
    PIXY_KEY_KP_7                   = 327,
    PIXY_KEY_KP_8                   = 328,
    PIXY_KEY_KP_9                   = 329,
    PIXY_KEY_KP_DECIMAL             = 330,
    PIXY_KEY_KP_DIVIDE              = 331,
    PIXY_KEY_KP_MULTIPLY            = 332,
    PIXY_KEY_KP_SUBTRACT            = 333,
    PIXY_KEY_KP_ADD                 = 334,
    PIXY_KEY_KP_ENTER               = 335,
    PIXY_KEY_KP_EQUAL               = 336,

    PIXY_KEY_LEFT_SHIFT             = 340,
    PIXY_KEY_LEFT_CONTROL           = 341,
    PIXY_KEY_LEFT_ALT               = 342,
    PIXY_KEY_LEFT_SUPER             = 343,
    PIXY_KEY_RIGHT_SHIFT            = 344,
    PIXY_KEY_RIGHT_CONTROL          = 345,
    PIXY_KEY_RIGHT_ALT              = 346,
    PIXY_KEY_RIGHT_SUPER            = 347,
    PIXY_KEY_MENU                   = 348,

    PIXY_KEY_LAST                   = PIXY_KEY_MENU,
};

/*! @brief Mouse button values.
 *
 *  Mouse button values.
 */
enum {
    PIXY_MOUSE_BUTTON_1,
    PIXY_MOUSE_BUTTON_2,
    PIXY_MOUSE_BUTTON_3,
    PIXY_MOUSE_BUTTON_4,
    PIXY_MOUSE_BUTTON_5,
    PIXY_MOUSE_BUTTON_6,
    PIXY_MOUSE_BUTTON_7,
    PIXY_MOUSE_BUTTON_8,

    PIXY_MOUSE_BUTTON_LAST      = PIXY_MOUSE_BUTTON_8,
    PIXY_MOUSE_BUTTON_LEFT      = PIXY_MOUSE_BUTTON_1,
    PIXY_MOUSE_BUTTON_RIGHT     = PIXY_MOUSE_BUTTON_2,
    PIXY_MOUSE_BUTTON_MIDDLE    = PIXY_MOUSE_BUTTON_3,
};

/*! @brief Window configurations.
 *
 *  Window configurations.
 */
typedef struct PixyWindowConfig {
    /*! The inital UTF-8 encoded window title.
     */
    char*       Title;
    /*! The desired width in screen coordinates, of the window.
     */
    int         Width;
    /*! The desired height in screen coordinates, of the window.
     */
    int         Height;
    /*! If this is true, VSync will be enabled upon creation, otherwise it is disabled.
     */
    int         VSync;
    /*! If this is true the window is shown upon creation, otherwise it is hidden.
     */
    int         Hidden;
} PixyWindowConfig;

/*! @brief Opaque window object.
 *
 *  Opaque window object.
 */
typedef struct PixyWindow PixyWindow;

/*! @brief Window size callback.
 *
 *  @param[in] win The window that has been resized.
 *  @param[in] width The new width in screen coordinates, of the window.
 *  @param[in] Height The new height in screen coordinates, of the window.
 *  Window size callback.
 */
typedef void (* PixyWindowSizeCallback)(PixyWindow* win, int width, int height);

/*! @brief Initializes the Pixy library.
 *
 *  This function initializes the Pixy library.  Before most Pixy functions can
 *  be used, Pixy must be initialized, and before an application terminates Pixy
 *  should be terminated in order to free any resources allocated during or after
 *  initialization.
 * 
 *  @return `PIXY_TRUE` if successful. or `PIXY_FALSE` if an error has occured.
 */
PIXYAPI int pixyInit();

/*! @brief Set a window hint value.
 *
 *  This function sets a window hint value.
 *  
 *  @param[in] hint The window hint to set.
 *  @param[in] value The new window hint value.
 */
PIXYAPI void pixyWindowHint(int hint, int value);

/*! @brief Creates a new window and its associated context.
 *
 *  This function creates a new window and its associated OpenGL context.
 *  Most of the options controlling how the window and its context are specified
 *  with the window configuration.
 *  @param[in] cfg The configurations of the window.
 *
 *  @return The handle of the created window, or `NULL` if an error has occured.
 */
PIXYAPI PixyWindow* pixyNewWindow(PixyWindowConfig cfg);

/*! @brief Sets the swap interval of the current context.
 *
 *  This function sets the swap interval of the current OpenGL context.
 * 
 *  @param[in] interval The swap interval.
 */
PIXYAPI void pixySwapInterval(int interval);

/*! @brief Sets the specified window's user data pointer.
 *
 *  This function sets the specified window's user data pointer.
 * 
 *  @param[in] win The window whose user data pointer gets set.
 *  @param[in] userData The user data pointer.
 */
PIXYAPI void pixySetUser(PixyWindow* win, void* userData);

/*! @brief Sets the closed flag of the specified window.
 *
 *  This function sets the closed flag of the specified window.
 * 
 *  @param[in] win The window whose closed flag to be set.
 *  @param[in] value The new value of the closed flag.
 */
PIXYAPI void pixySetClosed(PixyWindow* win, int value);

/*! @brief Get the specified window's user data pointer.
 *
 *  This function gets the specified window's user data pointer.
 * 
 *  @param[in] win The window to query.
 *  @return The user data pointer of the window.
 */
PIXYAPI void* pixyGetUser(PixyWindow* win);

/*! @brief Makes the specified window visible.
 *
 *  This function makes the specified window visible.
 * 
 *  @param[in] win The window to make visible.
 */
PIXYAPI void pixyShowWindow(PixyWindow* win);

/*! @brief Makes the specified window invisible.
 *
 *  This function makes the specified window invisible.
 */
PIXYAPI void pixyHideWindow(PixyWindow* win);

/*! @brief Sets the size callback of the specified window.
 *
 *  This function sets the size callback of the specified window.
 *  The callback gets called when the window gets resized.
 * 
 *  @param[in] win The window whose size callback to be set.
 *  @param[in] callback The window size callback.
 */
PIXYAPI void pixySetWindowSizeCallback(PixyWindow* win, PixyWindowSizeCallback callback);

/*! @brief Makes the context of the specified window current on the calling thread.
 *
 *  This function makes the OpenGL context of the specified window on the calling thread.
 * 
 *  @param[in] win The window whose context to make current, or `NULL` to detach the current
 *  context.
 */
PIXYAPI void pixyMakeCurrent(PixyWindow* win);

/*! @brief Check the closed flag of the specified window.
 *
 *  This function returns the closed flag of the specified window.
 * 
 *  @param[in] win The window to query.
 *  @return The value of the closed flag.
 */
PIXYAPI int pixyWindowClosed(PixyWindow* win);

/*! @brief Processes all pending events.
 *  
 *  This function processes only those events that are already in the event
 *  queue and then returns immediately.
 */
PIXYAPI void pixyPollEvents();

/*! @brief Swaps the front and back buffer of the specified window.
 *
 *  This function swaps the front and back buffer of the specified window when
 *  rendering with OpenGL.
 * 
 *  @param[in] win The window whose buffers to swap.
 */
PIXYAPI void pixySwapBuffers(PixyWindow* win);

/*! @brief Destroys the window and its associated context.
 *
 *  This function destroys the specified window and its context.
 *
 *  @param[in] win The window to destroy.
 */
PIXYAPI void pixyDeleteWindow(PixyWindow* win);

/*! @brief Terminates the Pixy library.
 *
 *  This function terminates the Pixy library.  Before an application terminates,
 *  it must terminate Pixy in order to free up any allocated resources that Pixy uses.
 */
PIXYAPI void pixyTerminate();

#ifdef __cplusplus
}
#endif

#endif

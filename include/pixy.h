
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

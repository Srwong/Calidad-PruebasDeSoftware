//package test;

import io.appium.java_client.MobileElement;
import io.appium.java_client.windows.WindowsDriver;
import java.net.MalformedURLException;
import java.net.URL;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.remote.RemoteWebElement;

public class appiumTest {

    private WindowsDriver<RemoteWebElement> driver;

    @Before
    public void setUp() throws MalformedURLException {
        DesiredCapabilities desiredCapabilities = new DesiredCapabilities();
        desiredCapabilities.setCapability("platformName", "Windows");
        desiredCapabilities.setCapability("deviceName", "WindowsPC");
        desiredCapabilities.setCapability("app", "c:\\windows\\system32\\notepad.exe");
        desiredCapabilities.setCapability("noReset", true);

        URL remoteUrl = new URL("http://localhost:4723/wd/hub");

        driver = new WindowsDriver<>(remoteUrl, desiredCapabilities);
    }

    @Test
    public void sampleTest() {
        RemoteWebElement el1 = driver.findElementByXPath("/Window/Edit");
        el1.sendKeys("Hola Mundo!");
        //driver.pressKeyCode((int)17);
        int key = 71;
        driver.pressKeyCode(key);


    }

    @After
    public void tearDown() {
        driver.quit();
    }
}
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

public class saveTest {

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
    public void sampleTest() throws InterruptedException {
        RemoteWebElement el1 = driver.findElementByXPath("/Window/Edit");
        el1.sendKeys("public class holaMundo {");
        el1.sendKeys("\n\tpublic static void main(String[] args) {");
        el1.sendKeys("\n\t\tSystem.out.println(\"Hola Mundo\");");
        el1.sendKeys("\n\t}");
        el1.sendKeys("\n}");
        //driver.pressKeyCode((int)17);
        //int key = 71;
        //driver.pressKeyCode(key);
        
        
        //MobileElement el2 = (MobileElement) driver.findElementByXPath("/Window/MenuBar/MenuItem[1]");
        //el2.click();
        //el2.sendKeys("g");
        //MobileElement el3 = (MobileElement) driver.findElementByXPath("/Window/MenuBar/MenuItem[1]/MenuItem[3]");
        //el3.click();
        /*MobileElement el6 = (MobileElement) driver.findElementByXPath("/Window/Window/Pane[1]/ComboBox[1]/Edit");
        el6.sendKeys("Nuevo.txt");
        MobileElement el7 = (MobileElement) driver.findElementByXPath("/Window/Window/Button[1]");
        el7.click();*/
        
        RemoteWebElement el2 = driver.findElementByXPath("/Window/MenuBar/MenuItem[1]");
        el2.click();
        el2.sendKeys("g");
        
        //Thread.sleep(5000);
        
        RemoteWebElement el3 = driver.findElementByXPath("/Window/Window/Pane[1]/ComboBox[2]");
        el3.sendKeys("t");
        
        RemoteWebElement el4 = driver.findElementByXPath("/Window/Window/Pane[1]/ComboBox[1]/Edit");
        el4.sendKeys("holaMundo.java");
        el4.click();

        RemoteWebElement el5 = driver.findElementByXPath("/Window/Window/Button[1]");
        el5.click();



    }

    @After
    public void tearDown() {
        //driver.quit();
    }
}
<?php

namespace SendGrid\Tests;

use \Mockery as m;
use \SendGrid as s;

class SendGridTest_Client extends \PHPUnit_Framework_TestCase {

  /**
   * Tear down test.
   */
  public function tearDown() {
    m::close();
  }

  /**
   * Test the version number.
   */
  public function testVersion() {
    $this->assertEquals(s\Client::VERSION, '1.0.7');
    $this->assertEquals(json_decode(file_get_contents('composer.json'))->version, \SendGrid\Client::VERSION);
  }

  /**
   * Test initializing client with API key.
   */
  public function testInitWithApiKey() {
    $sendgrid = new s\Client('token123456789');
    $this->assertEquals('SendGrid\Client', get_class($sendgrid));
    $this->assertNull($sendgrid->apiUser);
    $this->assertEquals($sendgrid->apiKey, 'token123456789');
  }

  /**
   * Test initializing client with API key and options.
   */
  public function testInitWithApiKeyOptions() {
    $sendgrid = new s\Client('token123456789', ['foo' => 'bar']);
    $this->assertEquals('SendGrid\Client', get_class($sendgrid));
  }

  /**
   * Test initializing client with API key with a proxy specified.
   */
  public function testInitWithProxyOption() {
    $sendgrid = new s\Client('token123456789', ['proxy' => 'myproxy.net:3128']);
    $this->assertEquals('SendGrid\Client', get_class($sendgrid));
    $options = $sendgrid->getOptions();
    $this->assertTrue(isset($options['proxy']));
  }

  /**
   * Test the default URL being returned by the client.
   */
  public function testDefaultURL() {
    $sendgrid = new s\Client('token123456789');
    $this->assertEquals('https://api.sendgrid.com', $sendgrid->url);
  }

  /**
   * Test the default endpoint being returned by the client.
   */
  public function testDefaultEndpoint() {
    $sendgrid = new s\Client('token123456789');
    $this->assertEquals('/api/mail.send.json', $sendgrid->endpoint);

  }

  /**
   * Test creating a client with a custom URL.
   */
  public function testCustomURL() {
    $options = [
      'protocol' => 'http',
      'host' => 'sendgrid.org',
      'endpoint' => '/send',
      'port' => '80',
    ];
    $sendgrid = new s\Client('token123456789', $options);
    $this->assertEquals('http://sendgrid.org:80', $sendgrid->url);
  }

  /**
   * Test creating a client with SSL verification turned off.
   */
  public function testSwitchOffSSLVerification() {
    $sendgrid = new s\Client('token123456789', ['turn_off_ssl_verification' => TRUE]);
    $options = $sendgrid->getOptions();
    $this->assertTrue(isset($options['turn_off_ssl_verification']));
  }

  /**
   * Test to make sure an exception is thrown when a non-200 response is returned.
   * This test is currently not working.
   *
   * @todo fix this test
   * @expectedException \SendGrid\Exception
   *
  public function testSendGridExceptionThrownWhenNot200() {
    $mockResponse = (object) [
      'code' => 400,
      'raw_body' => "{'message': 'error', 'errors': ['Bad username / password']}",
    ];

    $sendgrid = m::mock('SendGrid[postRequest]', ['token123456789']);
    $sendgrid->shouldReceive('postRequest')
      ->once()
      ->andReturn($mockResponse);

    $email = new s\Email();
    $email->setFrom('bar@foo.com')
      ->setSubject('foobar subject')
      ->setText('foobar text')
      ->addTo('foo@bar.com');

    $response = $sendgrid->send($email);
  }*/

  /**
   * Test creating a client and disabling exceptions being thrown.
   * This test is currently not working.
   *
   * @todo fix this test
   *
  public function testDisableSendGridException() {
    $mockResponse = (object) [
      'code' => 400,
      'raw_body' => "{'message': 'error', 'errors': ['Bad username / password']}",
    ];

    $sendgrid = m::mock('SendGrid[postRequest]', [
      'token123456789',
      ['raise_exceptions' => FALSE],
    ]);
    $sendgrid->shouldReceive('postRequest')
      ->once()
      ->andReturn($mockResponse);

    $email = new s\Email();
    $email->setFrom('bar@foo.com')
      ->setSubject('foobar subject')
      ->setText('foobar text')
      ->addTo('foo@bar.com');

    $response = $sendgrid->send($email);
  }*/

  /**
   * Make sure that exceptions do not get thrown if a 200 response is received.
   * This test is currently not working.
   *
   * @todo fix this test
   *
  public function testSendGridExceptionNotThrownWhen200() {
    $mockResponse = (object) [
      'code' => 200,
      'body' => (object) ['message' => 'success'],
    ];

    $sendgrid = m::mock('SendGrid[postRequest]', ['token123456789']);
    $sendgrid->shouldReceive('postRequest')
      ->once()
      ->andReturn($mockResponse);

    $email = new s\Email();
    $email->setFrom('bar@foo.com')
      ->setSubject('foobar subject')
      ->setText('foobar text')
      ->addTo('foo@bar.com');

    $response = $sendgrid->send($email);
  }*/
}


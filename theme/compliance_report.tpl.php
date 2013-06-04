<?php global $base_root; ?>
<?php if($results): ?>
  <table>
    <tbody>
      <tr>
        <th><?php print t('Node ID'); ?></th>
        <th><?php print t('Revision ID'); ?></th>
        <th><?php print t('Title'); ?></th>
        <th><?php print t('Status'); ?></th>
        <th><?php print t('Details'); ?></th>
      </tr>
      <?php foreach($results as $result): ?>
        <tr>
          <td><?php print $result->nid; ?></td>
          <td><?php print $result->vid; ?></td>
          <td><?php print $result->title; ?></td>
          <td><?php print $result->status; ?></td>
          <td><?php print l(t('Details'), $base_root . '/node/' . $result->nid . '/wcag'); ?></td>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
<?php else: ?>
<h2><?php print t('There are no compliance reports yet.'); ?></h2>
<?php endif; ?>

